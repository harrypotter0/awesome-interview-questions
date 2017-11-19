/*
give a bunch of job dependency, such as A-> B, A -> C, B-> D, and so on, implement two interfaces.
The first one is get_next_stage, which returns jobs in parallel for the next phase. 
The second is job_done, which tells you which job completed.
November 17, 2017 in United States  
*/

Solution ::

I assume:
- jobs are identified using an integer
- I get dependencies in the form of pairs (a, b) and the set of all a and all b
unioned gives me the set of all jobs.
- Semantics of the directed edge (a,b) is: in order to start b, a must be completed
- The dependencies form a DAG, no need to check for cycles
- you can call get_next_stage anytime and you will get the set of jobs that can
be started due to the calls of job_done since the last call of get_next_stage
(maybe a better name would be get_unlocked_jobs)
- you can only compete jobs that get_nextStage returned
- you can't complete a job twice

#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

ostream& operator <<(ostream& os, const vector<int>& v);

class JobScheduler
{
private: 
	unordered_map<int, unordered_set<int>> adjList_; // jobid -> list of dependent jobids
	unordered_map<int, int> incidentDeg_; // job, in-degree, jobs that have 
										  // in-degree 0 and are done are removed from HT
	vector<int> nextStage_;

public:
	JobScheduler(const vector<pair<int, int>>& deps) {
		for (auto dep : deps) {
			incidentDeg_[dep.first] += 0; // ensure they're in, don't change
			if (adjList_[dep.first].insert(dep.second).second) { 
				incidentDeg_[dep.second]++; // skip dublicate dependencies
			}
		}
		for (auto indeg : incidentDeg_) {
			if (indeg.second == 0) {
				nextStage_.push_back(indeg.first);
			}
		}
	}

	vector<int> get_nextStage() { 
		vector<int> res(move(nextStage_));  // clears nextStage_
		return res;
	}

	void jobDone(int jobId) {
		auto it = incidentDeg_.find(jobId);
		if (it == incidentDeg_.end() || it->second != 0) throw "error"; // see assumptions
		incidentDeg_.erase(it); // 
		for (auto next : adjList_[jobId]) {
			if (--incidentDeg_[next] == 0) {
				nextStage_.push_back(next);
			}
		}
	}
};


int main()
{
	JobScheduler s({
		{1, 2},
		{5, 2},
		{2, 3},
		{1, 2}, // dublicate dependency
		{3, 4},
		{4, 9},
		{7, 4},
		{2, 7},
		{2, 4}, // redundant 2, 3 -> 3, 4
		{2, 8} });

	cout << s.get_nextStage() << endl; // {1, 5}
	s.jobDone(1);
	cout << s.get_nextStage() << endl; // {}
	s.jobDone(5);
	cout << s.get_nextStage() << endl; // {2}
	s.jobDone(2);
	cout << s.get_nextStage() << endl; // {8, 3, 7}
	s.jobDone(8);
	cout << s.get_nextStage() << endl; // {}
	s.jobDone(3);
	cout << s.get_nextStage() << endl; // {}
	s.jobDone(7);
	cout << s.get_nextStage() << endl; // {4}
	s.jobDone(4);
	cout << s.get_nextStage() << endl; // {9}
	s.jobDone(9);
	cout << s.get_nextStage() << endl; // {}
}

ostream& operator <<(ostream& os, const vector<int>& v)
{
	os << "{";
	bool first = true;
	for (auto e : v) {
		if (!first) os << "," << e;
		else os << e;
		first = false;
	}
	os << "}";
	return os;
}
