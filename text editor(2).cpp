void search(){
    string word;
    string x;
    int count;
    count=0;
    cout<<"Enter the word you want to search about";
    cin>>word;
    ifstream file;
    file.open("y.txt");
    while(!file.eof()){
        file>>x;
        if (x==word){
            count ++;
        }
    }
    cout<<"the number of existence in the file is "
    <<count;
    
}
