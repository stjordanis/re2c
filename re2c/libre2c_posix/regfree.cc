#include "libre2c_posix/regex.h"
#include "src/nfa/nfa.h"
#include "src/dfa/dfa.h"


using namespace re2c;

void regfree(regex_t *preg)
{
    const nfa_t *nfa = preg->nfa;
    const dfa_t *dfa = preg->dfa;

    delete &dfa->charset;
    delete &dfa->rules;
    delete &dfa->tags;
    delete &dfa->mtagvers;
    delete[] dfa->finvers;
    delete &dfa->tcpool;

    delete dfa;
    delete nfa;
}
