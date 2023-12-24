from utils import pprint_color

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

# mov dest src
def mov(opr: list):
    reg[opr[0]] = reg[opr[1]]
    reg['pc'] = reg['pc']+1

# movv sp 80
def movv(opr: list):
    reg[opr[0]] = int(opr[1])
    reg['pc'] = reg['pc']+1


def load(opr: list):
    reg[opr[0]] = memory[int(opr[1])]
    reg['pc'] = reg['pc']+1

# loadr b acc: load to b from memory using the address in acc
def loadr(opr: list):
    reg[opr[0]] = memory[reg[opr[1]]]
    reg['pc'] = reg['pc']+1

# store 100 acc
def store(opr: list):
    memory[int(opr[0])] = reg[opr[1]]
    reg['pc'] = reg['pc']+1

# storer acc b
def storer(opr: list):
    memory[reg[opr[0]]] = reg[opr[1]]
    reg['pc'] = reg['pc']+1


def add(opr: list):
    reg['acc'] = reg[opr[0]]+reg[opr[1]]
    reg['pc'] = reg['pc']+1


def sub(opr: list):
    reg['acc'] = reg[opr[0]]-reg[opr[1]]
    reg['pc'] = reg['pc']+1


def mod(opr: list):
    reg['acc'] = reg[opr[0]] % reg[opr[1]]
    reg['pc'] = reg['pc']+1


def call(opr: list):
    reg['sp'] = reg['sp']+1
    memory[reg['sp']] = reg['pc']+1
    reg['pc'] = int(opr[0])


def ret(opr: list):
    reg['pc'] = memory[reg['sp']]
    reg['sp'] = reg['sp']-1


def out(opr: list):
    print(reg[opr[0]])
    reg['pc'] = reg['pc']+1


def push(opr: list):
    reg['sp'] = reg['sp']+1
    memory[reg['sp']] = reg[opr[0]]
    reg['pc'] = reg['pc']+1


def pop(opr: list):
    reg[opr[0]] = memory[reg['sp']]
    reg['sp'] = reg['sp']-1
    reg['pc'] = reg['pc']+1


def jmp(opr: list):
    reg['pc'] = int(opr[0])

# jnz 20 a
def jnz(opr: list):
    if reg[opr[1]] != 0:
        reg['pc'] = int(opr[0])
    else:
        reg['pc'] = reg['pc']+1


def halt(opr: list):
    reg['halt'] = True
    reg['pc'] = reg['pc']+1


def runm():
    while reg['halt'] == False:
        i: int = reg['pc']
        op: function = globals()[memory[i][0]]
        # print i,memory[i][0:]
        op(memory[i][1:])

        reg['timer'] = reg['timer']-1
        if reg['int'] == 1 and reg['timer'] == 0:
            reg['sp'] = reg['sp']+1
            memory[reg['sp']] = reg['pc']
            reg['pc'] = reg['ivec']
            reg['int'] = 0

        pprint_color(memory[i])
        pprint_color(reg)
        pprint_color(memory)
        # input()


if __name__ == "__main__":
    with open('ass-3.asm', 'r') as f:
        for l in f:
            if l.startswith("#"):
                continue

            comm = l.split()
            if comm:
                memory[int(comm[0])] = comm[1:]

    runm()
    print(reg)
    print(memory)
