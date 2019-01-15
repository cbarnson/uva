// Problem #    : 158A
// Created on   : 2019-01-14 20:09:04

var arr = readline().split(" ");
var n = arr[0];
var k = arr[1];

var l = readline().split(" ");
var kth = Number(l[k - 1]);
var cnt = 0;

for (var i = 0; i < l.length; i++) {
    var x = l[i];
    if (x >= kth && x > 0) {
        cnt++;
    }
}
print(cnt);