#include <iostream>
#include <fstream>
#include <cstring>
#include <filesystem>
#include "todo.hpp"

using namespace std;

const string user = getenv("USER");


void list()
{
  ifstream file("/home/" + user + "/.config/todo/list.txt");
      
  string line;
  int number = 1;
  while(getline(file, line))
  {
    cout << number << " " << line << "\n";
    ++number;
  }
}

void add(int argc, char* input)
{
  ofstream list;
  list.open ("/home/" + user + "/.config/todo/list.txt", ios_base::app);
  list << input << endl;
  list.close();
}

void clear()
{
  string newstr = "/home/" + user + "/.config/todo/list.txt";
  const char *c = newstr.c_str();
  remove(c);
}

void remove(int argc, char* input)
{
  int linetoremove = atoi(input);
  string contents, line;
  auto infile = ifstream("/home/" + user + "/.config/todo/list.txt");
  short currentline = 1;
  for (; getline(infile, line); ++currentline)
  {
    if (currentline != linetoremove)
    {
    contents += line + "\n";
    }
  }
  auto outfile = ofstream("/home/" + user + "/.config/todo/list.txt");
  outfile << contents;
}

int main(int argc, char* argv[])
{
  //check if there are enough arguments
  if (argc == 1){
    cout << "todo: not enough parameters" << endl;
    return 0;
  }
  // check if ~/.config/todo/ exists, and if not, create it
  if (! filesystem::is_directory("/home/" + user + "/.config/todo"))
  {
    filesystem::create_directory("/home/" + user + "/.config/todo");
  }

  string func(argv[1]);

  if (func == "add" && argc >= 3) add(argc, argv[2]);
  else if (func == "clear") clear();
  else if (func == "list") list();
  else if (func == "remove" && argc >= 3) remove(argc, argv[2]);
  
  return 0;
}
