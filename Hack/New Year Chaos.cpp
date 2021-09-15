void minimumBribes(vector<int> q) {
    int answer= 0;
    for(int i = q.size()-1 ; i >= 0 ; i--)
    {
        if(q[i] - (i+1) > 2){
            cout << "Too chaotic" << "\n";
            return;
        }
        for(int j = i+1; j < q.size();j++){
            if(q[i] > q[j])
                answer++;
        }
        
    }
    cout<< answer << "\n";
}