//https://leetcode.com/problems/sort-the-matrix-diagonally/
class Solution {
public:
	vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
		vector<vector<int>> diagonals;
		int height = mat.size();
		int width = mat[0].size();
		int max_diag_size = (height<width)?height:width;
		
		// идея: превратить диагонали в горизонтали путём смещения столбцов вверх на их номер по горизонтали
		
		// отсотритовать получившиеся строки
		
		// задвинуть столбцы обратно
		
	}
};