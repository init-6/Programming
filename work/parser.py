#!/usr/bin/python

import os
import commands
import sys

print "The list of tsc files checkedout are : "
#fin = open(commands.getoutput('twhich tkrmfx13.tsc'), 'r')
fin = open(sys.argv[1], 'r')
os.system('rm temp')
fout = open('temp', 'w+')
i = fin.readline()
root = 0
pdb = 0


def datconverter() :
	line = fin.readline()
	while line.find('endecho') == -1 :
		if line.find('alter database open') != -1 :
			fout.write(line)
			fout.write('if cdb\n')
			fout.write('     > sql ''alter pluggable database all open'';\n')
			fout.write('endif\n')
		else :
			fout.write(line)
		line = fin.readline()
	fout.write(line)

def sqlconverter() :
	line = fin.readline()
	while line.find('endecho') == -1 :
		fout.write(line)
		line = fin.readline()
	fout.write(line)

while i != '' :
	if i.find('echo') != -1 and i.find('>') != -1 and i.find('.dat') != -1 :
		fout.write('#BEGIN : RMAN script\n')
		fout.write(i)
		datconverter()
		fout.write('#END : RMAN script\n')

	elif i.find('echo') != -1 and i.find('>') != -1 and i.find('.sql') != -1 :
		fout.write(i)
		fout.write('#BEGIN : SQL script\n')
		sqlconverter()
		fout.write('#END : SQL script\n')

	elif i.find('shutdown') != -1 :
		fout.write('pdb root\n')
		fout.write(i)

	else :
		fout.write(i)
	i = fin.readline()

