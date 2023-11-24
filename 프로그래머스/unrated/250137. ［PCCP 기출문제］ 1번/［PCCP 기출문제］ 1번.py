def solution(bandage, health, attacks):
    answer = 0
    
    maxHealth = health
    stack = 0
    attTime, damage = [[attacks[j][i] for j in range(len(attacks))] for i in range(2)] 
    
    for time in range(0, attacks[len(attacks)-1][0]+1): 
        if time in attTime: # 몬스터 공격 타임
            health -= damage[attTime.index(time)]
            stack = 0
        else:   
            health += bandage[1]
        if health < maxHealth: # 현재 체력이 맥스면 회복 스킵
                if stack >= bandage[0]:
                    stack = 0
                    health += bandage[2]
        if health >maxHealth:
            health = maxHealth
        # print(time, health, stack)
        stack += 1
        if health <= 0:
            answer = -1
            break
    if health > 0:
        answer = health
    
    return answer