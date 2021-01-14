#include<bits/stdc++.h>
using namespace std;

vector <long long> road;
vector <int> graph;
int number;

int re_road(int index, long long type);
void make_graph();

int main(){
	int n, k, result=0;
	string inp, temp = "";
	vector <int> index, type;
	
	getline(cin, inp);
	n = stoi(inp);
	getline(cin, inp);
	for(int i=0; i<inp.size(); i++){
		if(inp[i] == ' '){
			road.push_back(stoi(temp));
			temp = "";
		}
		else
			temp.push_back(inp[i]);
	}
	road.push_back(stoi(temp));
	temp = "";
	
	getline(cin, inp);
	k = stoi(inp);
	
	for(int i=0; i<k; i++){
		getline(cin, inp);
		for(int j=0; j<inp.size(); j++){
			if(inp[j] == ' '){
				index.push_back(stoi(temp));
				temp = "";
			}
			else
				temp.push_back(inp[j]);
		}
		type.push_back(stoll(temp));
		temp = "";
	}
	
	make_graph();
	
	for(int i=0; i<k; i++)
		cout << re_road(index[i], type[i]) << endl;
}

void make_graph(){
	number = 1;
	graph.push_back(0);
	for(int i=1; i<road.size(); i++){
		if(road[i] == road[i-1])
			graph.push_back(graph[i-1]);
		else{
			graph.push_back(i);
			number++;
		}
	}
}

int re_road(int index, long long type){
	if(road[index-1] == type)
		return number;
		
	int n = road.size();
	if(index == 1){
		if(road[1] == road[0]){
			number++;
			for(int j=1; j<n; j++){
				if(road[j] == road[0])
					graph[j] = 1;
				else
					break;
			}
		}
		else{
			if(road[1] == type){
				number--;
				for(int j=1; j<n; j++){
					if(road[j] == type)
						graph[j] = 0;
					else
						break;
				}
			}
		}
	}
	else if(index<n){
		if(road[index-2] == road[index]){
			if(road[index-1] == road[index-2]){
				number += 2;
				graph[index-1] = index-1;
				for(int j=index; j<n; j++){
					if(road[j] == road[index])
						graph[j] = index;
					else
						break;
				}
			}
			else{
				if(type == road[index-2]){
					number -= 2;
					graph[index-1] = graph[index-2];
					for(int j=index; j<n; j++){
						if(road[j] == type)
							graph[j] = graph[index-1];
						else
							break;
					}
				}
			}
		}
		else{
			if(type == road[index-2]){
				graph[index-1] = graph[index-2];
				if(road[index-1] == road[index]){
					for(int j=index; j<n; j++){
						if(road[j] == road[index])
							graph[j] = index;
						else
							break;
					}
				}
				else
					number--;
			}
			else if(type == road[index]){
				graph[index-1] = index-1;
				if(road[index-1] != road[index-2])
					number--;
				for(int j=index; j<n; j++){
					if(road[j] == type)
						graph[j] = index-1;
					else
						break;
				}
			}
			else{
				graph[index-1] = index-1;
				for(int j=index; j<n; j++){
					if(road[j] == road[index])
						graph[j] = index;
					else
						break;
				}
				if(road[index-1] == road[index])
					number++;
				else if(road[index-1] == road[index-2])
					number++;
			}
		}
	}
	else{
		if(road[index-2] == road[index-1]){
			number++;
			graph[index-1] = index-1;
		}
		else if(road[index-2] == type){
			graph[index-1] = graph[index-2];
			number--;
		}
	}
	road[index-1] = type;
	return number;
}
