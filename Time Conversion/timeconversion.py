def timeConversion(s):
    # Write your code here
    zone = s[-2:]
    timearr = s[:-2].split(':')
    
    hour = int(timearr[0])
    minute = int(timearr[1])
    seconds = int(timearr[2])
    
    if zone == 'PM' and hour != 12:
        hour += 12
    elif zone == 'AM' and hour == 12:
        hour = 0
        
    return "{:02}:{:02}:{:02}".format(hour,minute, seconds)


s = '12:01:00PM'
s2 = '07:05:45PM'
print(timeConversion(s))
print(timeConversion(s2))
