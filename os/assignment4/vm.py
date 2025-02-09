# from utils import printc, printt

MEM_SIZE = 100

reg = {
    'a': 0,
    'b': 0,
    'c': 0,
    'd': 0,
    'e': 0,
    'f': 0,
    'sp': 0,
    'acc': 0,
    'pc': 0,
    'ivec': 0,
    'int': 0,
    'timer': 0,
    'halt': False
}

memory = [0]*MEM_SIZE


def mov(opr):
    reg[opr[0]] = reg[opr[1]]
    reg['pc'] = reg['pc']+1


def movv(opr):
    reg[opr[0]] = int(opr[1])
    reg['pc'] = reg['pc']+1


def load(opr):
    reg[opr[0]] = memory[int(opr[1])]
    reg['pc'] = reg['pc']+1


def loadr(opr):
    reg[opr[0]] = memory[reg[opr[1]]]
    reg['pc'] = reg['pc']+1


# store MEMORY_ADDRESS <- REGISTER
def store(opr):
    memory[int(opr[0])] = reg[opr[1]]
    reg['pc'] = reg['pc']+1

# storer 
def storer(opr):
    memory[reg[opr[0]]] = reg[opr[1]]
    reg['pc'] = reg['pc']+1


def add(opr):
    reg['acc'] = reg[opr[0]]+reg[opr[1]]
    reg['pc'] = reg['pc']+1


def sub(opr):
    reg['acc'] = reg[opr[0]]-reg[opr[1]]
    reg['pc'] = reg['pc']+1


def mod(opr):
    reg['acc'] = reg[opr[0]] % reg[opr[1]]
    reg['pc'] = reg['pc']+1


def call(opr):
    # move the top
    reg['sp'] = reg['sp']+1
    # store program couter + 1 in the stack
    memory[reg['sp']] = reg['pc']+1
    # store opr[0] in the pc to run next
    reg['pc'] = int(opr[0])


def ret(opr):
    reg['pc'] = memory[reg['sp']]
    reg['sp'] = reg['sp']-1


def out(opr):
    print(reg[opr[0]])
    reg['pc'] = reg['pc']+1


def push(opr):
    reg['sp'] = reg['sp']+1
    memory[reg['sp']] = reg[opr[0]]
    reg['pc'] = reg['pc']+1


def pop(opr):
    reg[opr[0]] = memory[reg['sp']]
    reg['sp'] = reg['sp']-1
    reg['pc'] = reg['pc']+1


def jmp(opr):
    reg['pc'] = int(opr[0])


def jnz(opr):
    if reg[opr[1]] != 0:
        reg['pc'] = int(opr[0])
    else:
        reg['pc'] = reg['pc']+1


def halt(opr):
    reg['halt'] = True
    reg['pc'] = reg['pc']+1


def runm():
    while reg['halt'] == False:
        i = reg['pc']
        op = globals()[memory[i][0]]
        # print i,memory[i][0:]
        op(memory[i][1:])
        pass

        reg['timer'] = reg['timer']-1
        if reg['int'] == 1 and reg['timer'] == 0:
            reg['sp'] = reg['sp']+1
            memory[reg['sp']] = reg['pc']
            reg['pc'] = reg['ivec']
            reg['int'] = 0

        # printc(memory[i])
        # printc(reg)
        # printc(memory)
        # # printt(reg, memory)
        # input()


if __name__ == '__main__':
    with open('prog.asm', 'r') as f:
        for l in f:
            if l.startswith("#"):
                continue

            comm = l.split()
            if comm:
                memory[int(comm[0])] = comm[1:]

        runm()

        print(reg)
        print(memory)
