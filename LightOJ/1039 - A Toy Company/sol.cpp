/*


Algorithm: BFS

In this problem, three letters comprises a node/state. By changing any letter, you can go to
one node/state to another node/state. So, say now you are in node/state 'adx'. From this node
you can go the following nodes (assuming that the following nodes are not forbidden):
bdx -- changing first letter
zdx
aex -- changing second letter
acx
ady -- changing third letter
adw

So you can say, these 6 nodes have an edge with the node 'adx'. So you have the nodes and edges,
construct the graph (keep forbidden words in mind) and then do a BFS from the calcuating the
shortest path between the starting and ending word.


*/


#include <bits/stdc++.h>

using namespace std;

map<string,bool> visited,block; //For visited string, and forbidden strings
 
//For storing a string, and how many changes has been made to
//the 'start' string in order to get the 'current' string
struct data
{
    string str;
    int count = 0;

    data(string s, int n)
    {
        str = s;
        count = n;
    }
};
 
//For checking if a string formation has been
//already created or not 
bool test(string str)
{
    if (visited[str]) 
    	return 0;

    return 1;
}
 
int bfs(string source, string destination)
{
    visited.clear();
    visited[source] = 1;

    data top(source, 0);

    queue<data>Q;
    Q.push(top);
 
    while(!Q.empty())
    {
        top = Q.front();
        Q.pop();
 
 		//If forbidden string then continue
        if (block[top.str])
            continue;

        //If destination that is 'end' string has been reached, the return 
        //count for how many changes has been made
        if(top.str == destination) 
        	return top.count;
 
 		//Since there are three letters in the toy, so loop upto three
 		//We will take two temp variables and change a letter by both
 		//incrementing and decrementing at the same time, to check whether
 		//we can reach our destination.
        for (int i = 0; i < 3; i++)
        {
            string temp = top.str;
            temp[i]++;

            //For handling cycle, as incrementing 'z' leads to 'a'
            //and decrementing 'a' leads to 'z', due to cycle.
            if (temp[i] == 'z' + 1)
                temp[i]='a';

            //If this string has not been created before, then push the date containing this string
            //and the steps required to get there in the queue.
            if (test(temp))
            {
                visited[temp] = 1;
                data v(temp, top.count + 1); //Previous string steps + 1 ==  current string steps/count.
                Q.push(v);
            }

            //Previously we incremented the letter, now we will decrement it 
            //in order to reach our destination.
            string tmp = top.str;
            tmp[i] -= 1;

            //For handling cycle, as incrementing 'z' leads to 'a'
            //and decrementing 'a' leads to 'z', due to cycle.
            if(tmp[i] == 'a' - 1)
                tmp[i] = 'z';

            if (test(tmp))
            {
                visited[tmp] = 1;
                data v(tmp, top.count + 1);
                Q.push(v);
            }
        }
    }

    return -1; //It is impossible to form the 'end' string.
}
int main()
{
    
    int T, testCase = 0;
    
    scanf("%d", &T);

    while (T--)
    {
        string str1, str2;
        cin >> str1 >> str2; //Start and End word
        
        int n; //Number of forbidden words
        scanf("%d", &n);

        for (int count = 0; count < n; count++)
        {
            string temp1, temp2, temp3; //The three letters
            cin >> temp1 >> temp2 >> temp3;

            //Loop through to insert the forbidden words
            for (int i = 0; i < temp1.size(); i++)
            {
                string concatTemp; //For concatenating all the letters from temp1, temp2 and temp3
                concatTemp += temp1[i];

                for (int j = 0; j < temp2.size(); j++)
                {
                    concatTemp += temp2[j];

                    for (int k = 0; k < temp3.size(); k++)
                    {
                        concatTemp += temp3[k];
                        block[concatTemp] = 1; //Insert the forbidden word, and mark it as true

                        //Erases character from index: end - 1, to end
                        //in this case it erases, the third character which is the last one
                        concatTemp.erase(concatTemp.end() - 1, concatTemp.end()); 
                    }

                    //In this case it erases the second character, which is the last one
                    concatTemp.erase(concatTemp.end() - 1, concatTemp.end());
                }

                //In this case it erases the first character which is the last one
                concatTemp.erase(concatTemp.end() - 1, concatTemp.end());
            }
        }

        printf("Case %d: %d\n", ++testCase, bfs(str1,str2));

        block.clear(); //Remove all the previous forbidden words

    }

    return 0;
}