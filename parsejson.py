import json

with open ('coordinates.json') as f:
    data = json.load(f)

lenght_of_products = (len(data["features"]["SymbolID"]["rings"]))

for x in range(length_of_back):

 print((data["features"]["SymbolID"][x]["rings"]))

