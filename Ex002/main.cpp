#include <ctime>
#include <fstream>
#include <iostream>
#include <random>
#include <string>

int longestPalindrome(std::string s)
{
	int n=static_cast<int>(s.length());
	int length=1, l;

	for(int i=0; i<n; i++){
		for(int j=i+1; j<=n; j++){
			l=1;
			if (s[i]==s[j]){	
				for (int k=1; k<=j-i; k++){
					if(s[i+k] == s[j-k]){
						l++;
					}
					else{
						break;
					}
				}
			}
			if (l>=length) length=l;
		}
	}
	return length;
}

int main()
{
	std::string s="banana";
	// std::string s="million";
	// std::string s="tracecars";
	std::cout << "Size of the longest palindrome: " << longestPalindrome(s) << std::endl;
	return 0;
}
