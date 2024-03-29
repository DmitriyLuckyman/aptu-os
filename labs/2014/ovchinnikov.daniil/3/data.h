#ifndef __DATA_H
#define __DATA_H

#include <time.h>
#include <iostream>
#include <vector>
#include <cstring>

struct FileDescriptor {
    int id;
    bool directory;             // if this is a directory
    int first_child;            // id of block with first child file descriptor
    int parent_file;            // id of block with parent file descriptor
    int next_file;              // id of block with next file descriptor
    int prev_file;              // id of block with next file descriptor
    int first_block;            // first data block
    size_t number_of_blocks;    // total blocks in file
    char name[10];              // filename
    time_t time;                // last updated time

//    FileDescriptor(const FileDescriptor & other) {
//        id = -1;
//        directory = other.directory;
//        first_child = -1;
//        parent_file = -1;
//        next_file = -1;
//        prev_file = -1;
//        first_block = -1;
//        number_of_blocks = other.number_of_blocks;
//        strncpy(name,other.name,sizeof(other.name));
//        time = time(0);
//    }
};

struct BlockDescriptor {
    int id;                     //
    int next;                   // next block id
    size_t len;                 // size of data written to block, -1 if block if full
};

struct Config {
    int block_size;             // size of block
    int block_number;           // number of blocks
};

template<typename T>
std::ostream & operator<<(std::ostream & out_, const std::vector<T> & v) {
    out_ << "total " << v.size() << " file(s)" << std::endl;
    for (auto it = v.begin(); it!=v.end(); ++it) {
        out_ << *it;
    }
    return out_;
}

inline std::ostream & operator <<(std::ostream & out_, const FileDescriptor & fd) {
    out_ << (fd.directory ? 'd' : 'f') << "\t '" << fd.name << "'\t";

    if  (fd.directory) {
        out_ << std::endl;
    } else {
        out_ << fd.number_of_blocks << " blocks";
        out_ << '\t' << ctime(&fd.time);
    }
    return out_;
}

#endif // __DATA_H
