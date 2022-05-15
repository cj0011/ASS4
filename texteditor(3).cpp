using namespace std;
void lower(){
    string x;
    ifstream file;
    file.open("y.txt");
    ofstream lowercasefile;
    lowercasefile.open("lower.txt");
    while(!file.eof()){
        file>>x;
        for(int j=0; j<x.length(); j++){
            x[j]= tolower(x[j]);
    }
    lowercasefile<<x<<" ";
    }
    lowercasefile.close();    
}
