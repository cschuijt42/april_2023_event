import json, requests

pokemon_name = input("Please enter a pokemon name: ")

url = "https://pokeapi.co/api/v2/pokemon/" + pokemon_name.lower()

r = requests.get(url)
if r.status_code != 200 :
  print("Something went wrong, sorry!")
  exit(1)

data = r.json()

print("Name: " + pokemon_name.capitalize())
print("Abilities:")

for ability in data["abilities"] :
  r = requests.get(ability["ability"]["url"])
  if r.status_code != 200 :
    print("Something went wrong, sorry!")
    exit(1)

  ability_names = r.json()["names"]
  output = [x["name"] for x in ability_names if x["language"]["name"] == "en" ][0]
  print("- " + output)
