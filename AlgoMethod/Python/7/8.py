# 2023/06/14 10:11:34
# 

teams = {
    "arurus": ["aruru", "erara", "ukuku", "usisi", "totoro"],
    "algos": ["dijkstra", "prim", "kruskal"],
    "ramdoms": ["fadj", "vuiawqpv", "qpcuvauavhjzcrb"],
    "keybords": ["qwerty", "yuiop", "asdf", "ghjkl"],
    "bocchi": ["hitori"]
}

# 答えを記録する変数
answer = 0

for c_num in range(ord("a"), ord("z") + 1):
    # "a" から "z" までの文字が順番に格納される
    c = chr(c_num)
    
    # 文字 c を含む人がどのチームにもいれば
    # answer の値を 1 だけ増やす
    all_teams_have_c = True
    for team_members in teams.values():
        # 文字 c を含む人が一人でもいれば
        # team_has_c が True に更新される
        team_has_c = False
        for name in team_members:
            if c in name:
                team_has_c = True
        # 文字 c を含む人がいないチームがあれば
        # all_teams_have_c は False に更新される
        if not team_has_c:
            all_teams_have_c = False
    if all_teams_have_c:
        answer += 1

# 答えを出力する
print(answer)