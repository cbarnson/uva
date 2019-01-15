// Problem #    : 71A
// Created on   : 2019-01-14 19:57:46

var n = Number(readline())
for (var i = 0; i < n; i++) {
    var str = readline();
    if (str.length > 10) {
        var ans = "";
        ans = str[0];
        ans += (str.length - 2).toString();
        ans += str[str.length - 1];
        print(ans);
    } else {
        print(str);
    }
}