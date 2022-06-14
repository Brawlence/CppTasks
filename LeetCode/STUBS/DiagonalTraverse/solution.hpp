//https://leetcode.com/problems/diagonal-traverse/

#define MIN(a,b) (a<b?a:b)
#define MOD(a) ( ((a) > 0) ? (a) : -(a))

//#define OUTPUT

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
	int m = mat.size();
	int n = mat[0].size();
	int total = m * n;
	int maxDiag = MIN(m,n);
	int repDiag = MOD(m-n);
	
	vector<int> result;
	result.reserve(total);
	
	/* BRRRRRRR in that order:
	\         max diagonal achieved, repeating diagonals start
	/        /    repeating diagonals end
	\  123/4/5678/
	/  23/4/5678/9
	\  3/4/5678/9A    - in the case m=n only the 123/4/9AB happens
	/  /4/5678/9AB
	\
	/  traversal direction is (-1)^(curr_diag-1), curr_diag E [1, repDiag + (2*maxDiag-1)]      
	\
	/                 0 <  currDiag <=  maxDiag               - we're on the rise (amt. of elements = currDiag)
	\           maxDiag < currDiag  <= repDiag + maxDiag      - steady            (amt. of elements = maxDiag)
	/ repDiag + maxDiag <  currDiag <= repDiag + 2*maxDiag -1 - decreasing        (amt. of elements = repDiag + 2*maxDiag - currDiag)
	\
	/ total amount of elements in diagonals ( MUST EQ total ): maxDiag*maxDiag + repDiag*maxDiag 
	\
	*/
	
	#ifdef OUTPUT
	    std::cout << "Matrix m×n, [" << m << "," << n << "], maximum diagonal D=" << maxDiag << ", skewed add. diagonals R=" << repDiag << std::endl;
	    std::cout << "The amount of elements in diagonals is " << ( maxDiag+repDiag ) * maxDiag << ", which SHOULD be equal to m×n = " << total << std::endl;
	    assert( ( maxDiag+repDiag ) * maxDiag == total);
	#endif
	
	int currDiag = 1;
	int cutoff = repDiag + (2*maxDiag) -1;

	int rem = 0;
	for (;currDiag <= cutoff;currDiag++) {
	    rem = currDiag%2;
	    if (currDiag <= maxDiag) {
		#ifdef OUTPUT
			std::cout << "↑ d" << currDiag << " elements: " << currDiag << std::endl; 
		#endif
		for (int i = 1; i <= currDiag; ++i) {
		    result.push_back(rem ? mat[currDiag-i][i -1] : 
					   mat[i -1][currDiag-i]);
		};
	    
	    } else if (currDiag <= maxDiag+repDiag) {
		#ifdef OUTPUT
			std::cout << "↻ d" << currDiag << " elements: " << maxDiag << std::endl;
		#endif
		for (int i = 1; i <= maxDiag; ++i) {
		    result.push_back(rem ? mat[ (m>n)*(currDiag-maxDiag) + maxDiag - i][ (m<n)*(currDiag-maxDiag) + i -1] :
					   mat[ (m>n)*(currDiag-maxDiag) + i -1][ (m<n)*(currDiag-maxDiag) + maxDiag - i]);
		};
		
	    } else {
		int remainingElem = (cutoff +1 - currDiag);
		#ifdef OUTPUT
		    std::cout << "↓ d" << currDiag << " elements: " << remainingElem << std::endl;
		#endif
		for (int i = 1; i <= remainingElem; ++i) {
			result.push_back(rem ? mat[m-i][n-(remainingElem-(i-1))] : 
								   mat[m-(remainingElem-(i-1))][n-i]);
		};        
	    }
	    
	
	};
	
	
	return result;
    }
};