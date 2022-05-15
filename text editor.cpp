void save(){
    char input[100];
    ifstream file;
    file.open("y.txt");
    fstream datafile; char fileName[81];
    cout << "Enter the name of a file: ";
    cin.getline(fileName, 81);
    datafile.open(fileName, ios::out);
    cout << "File " << fileName << " saved the data.\n";
    while(!file.eof()){
        file.getline(input,100);
        datafile<<input<<endl;
    }
    file.close();
    datafile.close();
}

