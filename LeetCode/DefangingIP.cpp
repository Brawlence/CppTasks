// https://leetcode.com/problems/defanging-an-ip-address/

class Solution {
public:
	string defangIPaddr(string address) {
		string res = "",replace = "[.]";
		for(int i = 0; i < address.size(); i++){
			if(address[i] == '.')
				res += replace;
			else
				res += address[i];      
		}
		return res; 
	}
};