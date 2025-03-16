from datetime import datetime

def time_to_seconds(time_str):
    minute, second = map(int, time_str.split(":"))
    return minute*60+second

def seconds_to_time(seconds):
    minute, second = divmod(seconds, 60)
    return f"{minute:02d}:{second:02d}"

def solution(video_len, pos, op_start, op_end, commands):
    answer = ''
    pos = time_to_seconds(pos)
    video_len = time_to_seconds(video_len)
    op_start = time_to_seconds(op_start)
    op_end = time_to_seconds(op_end)
    for com in commands:
        if pos >= op_start and pos <= op_end:
            pos = op_end
        if com == "next":
            if pos + 10 <= video_len :
                pos = pos + 10
            else:
                pos = video_len
        if com == "prev":
            if pos - 10 >= 0:
                pos = pos - 10
            else:
                pos = 0
    if pos >= op_start and pos <= op_end:
            pos = op_end
    
    answer = seconds_to_time(pos)
    
    return answer