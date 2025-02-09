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

memory = [0] * MEM_SIZE


def mov(opr):
    reg[opr[0]] = reg[opr[1]]
    reg['pc'] = reg['pc']+1


def movv(opr):
    reg[opr[0]] = int(opr[1])
    reg['pc'] = reg['pc']+1


def sub(opr):
    reg['acc'] = reg[opr[0]]-reg[opr[1]]
    reg['pc'] = reg['pc']+1


def add(opr):
    reg['acc'] = reg[opr[0]]+reg[opr[1]]
    reg['pc'] = reg['pc']+1


def mod(opr):
    reg['acc'] = reg[opr[0]] % reg[opr[1]]
    reg['pc'] = reg['pc']+1


def out(opr):
    print(reg[opr[0]])
    reg['pc'] = reg['pc']+1


def halt(opr):
    reg['halt'] = True
    reg['pc'] = reg['pc']+1


def runm():
    while reg['halt'] == False:
        # address of the currently runnning command
        i = reg['pc'] # 0 at the begining
        # gets the function name that has to run
        op = globals()[memory[i][0]]
        # run the command
        op(memory[i][1:])

        reg['timer'] = reg['timer']-1
        if reg['int'] == 1 and reg['timer'] == 0:
            reg['sp'] = reg['sp']+1
            memory[reg['sp']] = reg['pc']
            reg['pc'] = reg['ivec']
            reg['int'] = 0


        pprint_color(memory[i])
        pprint_color(reg)


if __name__ == '__main__':
    # commands are loaded to the memory
    with open('ass-1.asm', 'r') as file:
        for line in file:
            # comment lines are ignored
            if line.startswith("#"):
                continue

            command = line.split()

            if command:
                memory[int(command[0])] = command[1:]

    # pprint_color(memory)

    runm()

    pprint_color(reg)
    pprint_color(memory)
