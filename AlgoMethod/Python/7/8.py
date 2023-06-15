# 2023/06/15 20:37:40
# 2023/06/15 20:51:05 AC.

teams = {
    "arurus": ["aruru", "erara", "ukuku", "usisi", "totoro"],
    "algos": ["dijkstra", "prim", "kruskal"],
    "ramdoms": ["fadj", "vuiawqpv", "qpcuvauavhjzcrb"],
    "keybords": ["qwerty", "yuiop", "asdf", "ghjkl"],
    "bocchi": ["hitori"]
}

def teamHas(list_members, c):
    for name in list_members:
        if c in name:
            return True
    return False

def allTeamsHave(teams, c):
    for list_members in teams.values():
        if not teamHas(list_members, c):
            return False
    return True

for c_num in range(ord("a"), ord("z") + 1):
    # "a" から "z" までの文字が順番に格納される
    c = chr(c_num)
    
    if allTeamsHave(teams, c):
        print(c)
