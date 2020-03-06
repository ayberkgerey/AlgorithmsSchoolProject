import json

with open ('coordinates.json') as f:
    data = json.load(f)

print(data)