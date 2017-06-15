// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"
#include <iostream>
#include <stdio.h>
#include <tchar.h>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

#define MAX_V 256;

/*
struct edge {
	int to;
	int cost;
};
*/
using namespace std;

void BFS_Traversal(vector<char> * G);
void DFS_Traversal(vector<char> * G);
// TODO: reference additional headers your program requires here
