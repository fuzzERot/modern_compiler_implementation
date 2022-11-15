#include "program.hpp"
#include "util.hpp"

int counter(A_expList expList) {
    if(expList->kind == A_expList_::A_lastExpList) {
        return 1;
    }

    return 1 + counter(expList->u.pair.tail);
}

int maxargs(A_stm prog) {
    switch (prog->kind)
    {
    case A_stm_::A_compoundStm:
        {
            int left = maxargs(prog->u.compound.stm1);
            int right = maxargs(prog->u.compound.stm2);
            return right > left ? right : left;
        }
        break;
    case A_stm_::A_assignStm:
        {
            if(prog->u.assign.exp->kind != A_exp_::A_eseqExp) {
                return 0;
            }

            return maxargs(prog->u.assign.exp->u.eseq.stm);
        }
        break;
    case A_stm_::A_printStm:
        {
            return counter(prog->u.print.exps);
        }
        break;
    default:
        break;
    }  

    return 0; 
}

typedef struct table *Table_;
struct table {
    std::string id; 
    int value; 
    Table_ tail;
};

Table_ Table(std::string id, int value, table *tail) {
    Table_ t = Storage::getInstance().addValue<table>(sizeof(table));
    t->id = id; 
    t->value = value; 
    t->tail = tail;
    return t;
}

Table_ interpStm(A_stm s, Table_ t) {
    
}

void interp(A_stm prog) {

}
