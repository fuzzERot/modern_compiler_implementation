#include "util.hpp"
#include "slp.hpp"

A_stm A_CompoundStm(A_stm stm1, A_stm stm2)
{
    auto s = Storage::getInstance().addValue<A_stm_>(sizeof(A_stm_));

    s->kind = A_stm_::A_compoundStm;
    s->u.compound.stm1 = stm1;
    s->u.compound.stm2 = stm2;
    return s;
}

A_stm A_AssignStm(std::string id, A_exp exp)
{   
    auto s = Storage::getInstance().addValue<A_stm_>(sizeof(A_stm_));

    s->kind = A_stm_::A_assignStm;
    s->u.assign.id = id;
    s->u.assign.exp = exp;
    return s;
}

A_stm A_PrintStm(A_expList exps)
{
    auto s = Storage::getInstance().addValue<A_stm_>(sizeof(A_stm_));

    s->kind = A_stm_::A_printStm;
    s->u.print.exps = exps;
    return s;
}

A_exp A_IdExp(std::string id)
{
    auto e = Storage::getInstance().addValue<A_exp_>(sizeof(A_exp_));

    e->kind = A_exp_::A_idExp;
    e->u.id = id;
    return e;
}

A_exp A_NumExp(int num)
{
    auto e = Storage::getInstance().addValue<A_exp_>(sizeof(A_exp_));

    e->kind = A_exp_::A_numExp;
    e->u.num = num;
    return e;
}

A_exp A_OpExp(A_exp left, A_binop oper, A_exp right)
{
    auto e = Storage::getInstance().addValue<A_exp_>(sizeof(A_exp_));

    e->kind = A_exp_::A_opExp;
    e->u.op.left = left;
    e->u.op.oper = oper;
    e->u.op.right = right;
    return e;
}

A_exp A_EseqExp(A_stm stm, A_exp exp)
{
    auto e = Storage::getInstance().addValue<A_exp_>(sizeof(A_exp_));

    e->kind = A_exp_::A_eseqExp;
    e->u.eseq.stm = stm;
    e->u.eseq.exp = exp;
    return e;
}

A_expList A_PairExpList(A_exp head, A_expList tail)
{
    auto e = Storage::getInstance().addValue<A_expList_>(sizeof(A_expList_));

    e->kind = A_expList_::A_pairExpList;
    e->u.pair.head = head;
    e->u.pair.tail = tail;
    return e;
}

A_expList A_LastExpList(A_exp last)
{
    auto e = Storage::getInstance().addValue<A_expList_>(sizeof(A_expList_));

    e->kind = A_expList_::A_lastExpList;
    e->u.last = last;
    return e;
}
