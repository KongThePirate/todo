#include <iostream>
#include <fstream>
#include <cstring>
#include <filesystem>

using namespace std;


void list()
{
  string user = getenv("USER");
  ifstream file("/home/" + user + "/.config/todo/list.txt");
      
  string line;
  int number = 1;
  while(getline(file, line))
  {
    cout << number << " " << line << "\n";
    ++number;
  }
}

int main(int argc, char* argv[]){
  string user = getenv("USER");
  if (! filesystem::is_directory("/home/" + user + "/.config/todo")){
    filesystem::create_directory("/home/" + user + "/.config/todo");
  }

  // some variables
  char add1[ ] = "add";
  char remove1[ ] = "remove";
  char clear1[ ] = "clear";
  char list1[ ] = "list";
  
// Arguments
  if (argc >= 2)
  {
    if (strcmp(argv[1], add1) == 0)
    {
      if (argc >= 3)
      {
        string a;
        a = argv[2];
        ofstream list;
        list.open ("/home/" + user + "/.config/todo/list.txt", ios_base::app);
        list << a << endl;
        list.close();
      }
      else
      {
        cout << "todo add: not enough arguments" << endl;
      }
    }
    else if (strcmp(argv[1], clear1) == 0)
    {
      string newstr = "/home/" + user + "/.config/todo/list.txt";
      const char *c = newstr.c_str();
      remove(c);
    }
    else if (strcmp(argv[1], remove1) == 0)
    {
      if(argc >= 3)
      {
        int linetoremove = atoi(argv[2]);
        string contents, line;
        auto infile = ifstream("/home/" + user + "/.config/todo/list.txt");
        short currentline = 1;
        for (; getline(infile, line); ++currentline)
        {
          if (currentline != linetoremove)
          {
            contents += line;
          }
        }
        auto outfile = ofstream("/home/" + user + "/.config/todo/list.txt");
        outfile << contents;
      }
      else{cout << "todo remove: not enough arguments" << endl;}
    }
    else if (strcmp(argv[1], list1) == 0)
    {
      list();
    }
    else
    {
      cout << "todo: invalid arguments" << endl;
    }
  }
  else
  {
    cout << "todo: missing argument \nCheck 'todo help' for more information." << endl;
  }
  return 0;
}
