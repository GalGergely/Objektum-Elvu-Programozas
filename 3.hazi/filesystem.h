#pragma once

#include <vector>

class File
{
private:
    int _size;
public:
    File(int i) {_size=i;}
    ~File() {}
    int get_Size() {return _size;}
};

class Folder
{
private:
    int _folderSize=0; 
    std::vector<Folder*> _folders;
    std::vector<File*> _files;
public:
    Folder(){}
    ~Folder(){}
    void add(File* _file)  {_files.push_back(_file); _folderSize+=_file->get_Size();}
    void add(Folder* _folder) {_folders.push_back(_folder); _folderSize++; _folderSize+=_folder->getSize(); } 
    int getSize() {
        int tmp=0;
        for(int i=0; i<_files.size(); i++)
        {
            tmp+=_files[i]->get_Size();
        }
        for(int i=0; i<_folders.size(); i++)
        {
            tmp+=_folders[i]->getSize();
        }
        _folderSize=tmp;
        return _folderSize;}

};

class FileSystem
{
private:
public:
    Folder root;
    FileSystem() {}
    ~FileSystem() {}
    
};

