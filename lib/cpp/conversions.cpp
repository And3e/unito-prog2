#include "conversions.h"

// isTypes

bool isInt(string s){
 if (s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))){
  return false;
 }

 char* p;
 strtol(s.c_str(), &p, 10);

 return (*p==0);
}

bool isLongInt(string str){
 try{
  long int n=stol(str);
  (void)n;
  return true;
 } catch (const invalid_argument& ia){
  return false;
 } catch (const out_of_range& oor){
  return false;
 }
}

bool isFloat(string str){
 try{
  float n=stof(str);
  (void)n;
  return true;
 } catch (const invalid_argument& ia){
  return false;
 } catch (const out_of_range& oor){
  return false;
 }
}

bool isDouble(string str){
 try{
  double n=stod(str);
  (void)n;
  return true;
 } catch (const invalid_argument& ia){
  return false;
 } catch (const out_of_range& oor){
  return false;
 }
}

bool isChar(string str){
 return (str.length()==1);
}

// input check

char getCond(string in){
 char out;

 if(in=="int"){
  out='i';
 } else if(in=="long int"){
  out='l';
 } else if(in=="float"){
  out='f';
 } else if(in=="double"){
  out='d';
 } else if(in=="char"){
  out='c';
 }

 return out;
}

bool inputCheck(string in, string param){
 char cond=getCond(param);
 bool out;

 switch(cond){
  case 'i':{
   out=isInt(in);
  break;
  }
  case 'l':{
   out=isLongInt(in);
  break;
  }
  case 'f':{
   out=isFloat(in);
  break;
  }
  case 'd':{
   out=isDouble(in);
  break;
  }
  case 'c':{
   out=isChar(in);
  break;
  }
 }

 return out;
}

// string utils
vector<string> split(string in, string sep){
	vector<string> out;
	while(in.size()){
		unsigned int i=in.find(sep);
		if(i!=string::npos){
			out.push_back(in.substr(0, i));
			in=in.substr(i+sep.size());
			if(in.size()==0){
    out.push_back(in);
   }
		}
		else{
			out.push_back(in);
			in="";
		}
	}
	return out;
}

string trim(string in, char sep){
 for(unsigned int i=0; i<in.length(); i++){
  if(in[i]==sep){
   in.erase(i, 1);
  }
 }

 return in;
}

string substring(string in, int inizio, int fine){
 string out="";

 for(int i=inizio; i<fine; i++){
  out+=in[i];
 }

 return out;
}

// conversions