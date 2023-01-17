#include <iostream>
#include <string>
#include "./string_calculator.h"

using std::cout, std::endl;
using std::string;



string compare(string x, string y){
	if(x.size() == y.size()){  
		for(int i = 0; i < x.size(); i++){
			if(x[i] > y[i]){
				return x;
				cout << x[i] << endl;
				break; 
			}		
			if(y[i] > x[i]){
				return y;
				break;
			}
		}
	}
	if(x.size() > y.size()){
		return x;
	}
	return y;
} 
unsigned int digit_to_decimal(char digit) {
	digit = (unsigned int)digit - 48;
		if (digit < 0 || digit > 9 ){
			throw std::invalid_argument("invalid argu");
		}
    return digit;
}

char decimal_to_digit(unsigned int decimal) {
	char dessmal = decimal+48;
	if (decimal > 9 ){
		throw std::invalid_argument("hinvalid harg");
	}
    return dessmal;
}
string trim_leading_zeros(string num) {
	unsigned int counter = 0;
	int endpnt = 0;
	string minus = "-";
	bool negg = num[0]== '-';
	if (num[0]== '-'){
		num = num.substr(1,num.size()-1);
	}
    for (unsigned int i = 0; (unsigned)i < num.size(); i++){
		if(num.at(i) == '0'){
			counter += 1;
		}
		else {
			i = num.size();
		}
	}
	if(num.size() == counter){
		return "0";
	}
	endpnt = num.size()- counter;
	num = num.substr(counter, endpnt);
	if (negg == true){
		num = minus.append(num);
	}
    return num;
}

string add(string lhs, string rhs) {
	char zero = '0';
	string output = "";
	int empty = 0;
	int num;
	bool neg = false;
	string mynus = "-";
	if (rhs == "0"){
		return lhs;
	}
	if (lhs == "0"){
		return rhs;
	}
	if ((lhs[0] == '-') && (rhs[0] == '-')){
			neg = true;
			lhs = lhs.substr(1,lhs.size()-1);
			rhs = rhs.substr(1,rhs.size()-1);
	}
	if ((lhs[0] != '-') && (rhs[0] == '-')){
		rhs = rhs.substr(1,rhs.size()-1);
		return subtract(lhs, rhs);
	}
	if ((lhs[0] == '-') && (rhs[0] != '-')){
		rhs = mynus.append(rhs);
		return subtract(lhs, rhs);
	}
	
	if (lhs.size() > rhs.size()){
		int x_1 = lhs.size();
		int y_1 = rhs.size();
		int counter = x_1 - y_1;
		for (unsigned int i = 0; i < counter; i++){
			rhs = zero+rhs;
			if (rhs.size() == lhs.size()){
				i = counter;
			}  
		}
	}
	if (lhs.size() < rhs.size()){
		int counter = (rhs.size()-lhs.size());
		for (unsigned int i = 0; i < counter; i++){
			lhs = zero+lhs;
		}
	}
	if (lhs.size() == rhs.size()){
		rhs = zero+rhs;
		lhs = zero+lhs;
	}
	for (unsigned int i = lhs.size()-1; i >= 0; i--){
		char X_2 = lhs[i];
		char y_2 = rhs[i];
		num = digit_to_decimal(X_2)+ digit_to_decimal(y_2) + empty;
		empty = 0;
		if (num > 9){
			empty = num/10;
			num = num%10;
		}
		output = decimal_to_digit(num)+output;
	}
	if (output[0]=='0'){
		output = trim_leading_zeros(output);
	}
	if (neg == true ){
		output = mynus.append(output);
	}
    return output;
}

string subtract(string lhs, string rhs) {
	char zro = '0';
	string myns = "-";
	bool neggg = false;
	int Num;
	int magic = 0;
	string autput = "";
	if (rhs == "0"){
		return lhs;
	}
	if (lhs == "0"){
		return myns.append(rhs);
	}
	if (rhs == lhs){
		return "0";
	}
	
	if (lhs[0] == '-' && rhs[0] == '-'){
		lhs = lhs.substr(1,lhs.size()-1);
		rhs = rhs.substr(1,rhs.size()-1);
		string A_1 = rhs;
		string B_1 = lhs;
		if(compare(lhs, rhs) == lhs){
			neggg = true;
		}
		else{
			lhs = A_1;
			rhs = B_1;
		}
	}
	// when lhs is positive but rhs is negative 
	else if ((lhs[0]!= '-' && rhs[0] == '-')){
		rhs = rhs.substr(1,rhs.size()-1);
		return add(lhs,rhs);
	}
	// when lhs is negative but rhs is positive
	else if ((lhs[0]== '-' && rhs[0]!= '-')){
		rhs = myns.append(rhs);
		return add(lhs,rhs);
	}
	// when both lhs and rhs are positive
	else if ((lhs[0]!= '-' && rhs[0] != '-')){
		string A_2 = lhs;
		string B_2 = rhs;
		if (compare(lhs,rhs) == lhs){
			neggg = false;
		}
		else {
			neggg = true;
			lhs = B_2;
			rhs = A_2;
		}
	}
    if (lhs.size() > rhs.size()){
		int j_1 = lhs.size();
		int k_1 = rhs.size();
		int kounter = j_1 - k_1;
		for (unsigned int i = 0; i < kounter; i++){
			rhs = zro+rhs;
			if (rhs.size() == lhs.size()){
				i = kounter;
			}  
		}
	}
	if (lhs.size() < rhs.size()){
		int kounter = (rhs.size()-lhs.size());
		for (unsigned int i = 0; i < kounter; i++){
			lhs = zro+lhs;
		}
	}
	if (lhs.size() == rhs.size()){
		rhs = zro+rhs;
		lhs = zro+lhs;
	}
	
	for (int i = lhs.size()-1;i >= 0; i--){
		char j_2 = lhs[i];
		char k_2 = rhs[i];
		int deck_1 = digit_to_decimal(j_2);
		int deck_2 = digit_to_decimal(k_2);
		Num = deck_1 - deck_2 - magic;
		magic = 0;
		if (Num < 0 && lhs[i-1] > 0){
			Num = 10 + Num;
			magic = 1;
			}
		autput = decimal_to_digit(Num)+autput;
		}
		
	if (autput[0]=='0'){
		autput = trim_leading_zeros(autput);
	}
	if (neggg == true ){
		autput = myns.append(autput);
	}
		
    return autput;
}

string multiply(string lhs, string rhs){
	int dot;
	string zro = "";
	string product = "";
	string second = "0";
	string third = "";
	bool neg = false;
	int one = 0; 
	string myns = "-";
	if(lhs == "0" || rhs == "0"){
		return "0";
	}
	if (lhs == "1"){
		return rhs;
	}
	if (rhs == "1" ){
		return lhs;
	}
	if ((lhs[0] == '-') && (rhs[0] == '-')){
			lhs = lhs.substr(1,lhs.size()-1);
			rhs = rhs.substr(1,rhs.size()-1);
	}
	if ((lhs[0] != '-') && (rhs[0] == '-')){
		neg = true;
		rhs = rhs.substr(1,rhs.size()-1);
	}
	if ((lhs[0] == '-') && (rhs[0] != '-')){
		cout << "hey " << endl; 
		neg = true;
		lhs = lhs.substr(1,lhs.size()-1);
	}
	if(rhs > lhs){
		string A = rhs;
		string B = lhs;
		lhs = A;
		rhs = B;
	}
	for (unsigned int i = rhs.size()-1 ; i >= 0 ; i--){
		for (unsigned int j = lhs.size()-1; j >=0; j--){
			dot = digit_to_decimal(lhs[j])* digit_to_decimal(rhs[i])+one;
			one = 0;
			if (dot > 9){
			one = dot/10;
			dot = dot%10;
			}
			product = decimal_to_digit(dot) + product;
			if(j == 0 && one > 0){
				product = decimal_to_digit(one) + product;
				one = 0;
			}
		}
		third = product + zro;
		zro += "0";
		second = add(third,second);
		product = "";
	}
	if (neg == true ){
		second = myns.append(second);
	}
    return second;
}
