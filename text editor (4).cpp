
void upper(){
    string x;
    ifstream file;
    file.open("y.txt");
    ofstream uppercasefile;
    uppercasefile.open("upper.txt");
    while(!file.eof()){
        file>>x;
        for(int j=0; j<x.length(); j++){
            x[j]= toupper(x[j]);
    }
    uppercasefile<<x<<" ";
    }
    uppercasefile.close();    
}
