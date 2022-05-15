void first(){
    string x;
    ifstream file;
    file.open("y.txt");
    ofstream firstcipsfile;
    firstcipsfile.open("first.txt");
    while(!file.eof()){
        file>>x;
        for(int j=0; j<x.length();j++){
            if (j==0){
                x[j]= toupper(x[j]);
            }
            else{
                x[j]=tolower(x[j]);
            }
    }
    firstcipsfile<<x<<" ";
    }
    firstcipsfile.close();    
}

