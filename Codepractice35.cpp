int countSwaps(vector<int> &perm){
    int n = perm.size();
    vector<int> mp(n, 0);
    int transpositions = 0;

    for(int i = 0; i < n; i++){
        if(mp[i] == 1) continue;

        int first_element = i;
        int curr_element = i;
        int cyclen = 0;

        while(perm[curr_element] != first_element){
            mp[curr_element] = 1;
            cyclen++;
            curr_element = perm[curr_element];
        }

        mp[curr_element] = 1;
        cyclen++;

        transpositions += cyclen - 1;
    }

    return transpositions;
}