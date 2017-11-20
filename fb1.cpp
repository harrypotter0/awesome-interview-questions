/*
Give a matrix, for example
1 0 0 1 0
0 0 1 0 1
0 0 0 1 0
1 0 1 0 1
Find if there is a rectangle in the matrix, all four corners are 1
For the example,  there is only one rectangle, that is
1 0 1
0 1 0
1 0 1

November 14, 2017
*/

//Solution :::

bool isRectangle( const vector<vector<int>>&  matrix )
{
	int rows = matrix.size();
	if(rows == 0 ) return false;
	int columns = matrix[0].size();
	
	unordered_map<int, unordered_set<int>> table;
	
	for( int i=0; i<rows; ++i)
	{
		
		for( int j=0; j<columns-1; ++j)
		{
			for(int k=j+1; k<columns; ++k)
			{
				if( matrix[i][j]==1 && matrix[i][k]==1)
				{
					if( table.find(j) != table.end() && table[j].find(k) != table[j].end() )
					{
						return true;
					}
					if( table.find(k) != table.end() && table[k].find(j) != table[k].end() )
					{
						return true;
					}
					table[j].insert(k);
					table[k].insert(j);
				}
			}
		}
	}
	return false;
}

