
def parseProfile(filename):
    pfile = open(filename, 'r')
    plist = pfile.readlines()
    pfile.close()
    pumpdict = {}
    sensordict = {}
    for str in plist:
        line = str.split('{')   
        pairs = line[1].split()
    pairdict = {}
    for pair in pairs:
        splpair = pair.split(':')
        pairdict[splpair[0]] = splpair[1]
    if line[0] == "pump":
        pumpdict[pairdict["name"]] = pairdict
    elif line[0] == "sensor":
        sensordict[pairdict[name]] = pairdict

    return  pumpdict, sensordict
