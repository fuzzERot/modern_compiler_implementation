#pragma once
#include <assert.h>
#include <memory>
#include <stdexcept>
#include <vector>
#include <cstring>
#include "slp.hpp"

//typedef char *string;
//typedef char bool;

#define TRUE 1
#define FALSE 0

//void *checked_malloc(int);
//string String(char *);

//typedef struct U_boolList_ *U_boolList;
//struct U_boolList_ {bool head; U_boolList tail;};
//U_boolList U_BoolList(bool head, U_boolList tail);

using byte_t = char;

struct Storage {
    // change for map pointer->vector
    static Storage& getInstance() {
        static Storage storage;

        return storage;
    }

    template<typename _Type>
    _Type* addValue(size_t size) {
        std::vector<byte_t> buf(size);
        data_.emplace_back(std::move(buf));
        auto pointer = data_.back().data();

        return reinterpret_cast<_Type*>(pointer);
    }

private:
    Storage() = default;
    Storage(const Storage* rhs) = delete;
    Storage(Storage && rhs) = delete;

    std::vector<std::vector<byte_t>> data_;
};

