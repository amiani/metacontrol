
def parseProfile(filename):
    pfile = open(filename, 'r')
    plist = pfile.readlines()
    pfile.close()
    portdict = {}
    for str in plist:
        line = str.split(';')
        pairs = line[1].split(':')
        pdict[line[0]] = 
