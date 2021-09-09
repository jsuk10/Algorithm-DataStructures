void minimumBribes(vector<int> q) {
    //min, nextMin
    int minarr[2] = {q[q.size()-1], q[q.size()-2]};
    int answer= 0;
    for(int i = q.size()-2 ; i >= 0 ; i--)
    {
        if(q[i] - (i+1) > 2){
            cout << "Too chaotic" << "\n";
            return;
        }
        
        if(q[i] > minarr[0])
            answer ++;
        if (q[i] > minarr[1])
            answer++;
        
        if(q[i] < minarr[0]){
            minarr[1] = minarr[0];
            minarr[0] = q[i];
        }else if (q[i] < minarr[1])
            minarr[1] = q[i];
    }
    cout<< answer << "\n";
}