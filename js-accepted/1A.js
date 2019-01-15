// Problem #    : 1A
// Created on   : 2019-01-15 00:40:22
process.stdin.resume();
process.stdin.setEncoding("utf8");

var input = "",
  readline,
  print;

process.stdin.on("data", function(chunk) {
  input += chunk;
});

process.stdin.on("end", function() {
  input = input.split(/\r?\n/);
  print = function(data) {
    process.stdout.write(data + "\n");
  };
  var inputLineIndex = 0;
  readline = function() {
    return inputLineIndex >= input.length ? undefined : input[inputLineIndex++];
  };
  process.exit(main() || 0);
});

function main() {
  // Your code here
  let [n, m, a] = readline().split(" ");

  let x = Math.floor(n / a) + (n % a == 0 ? 0 : 1);
  let y = Math.floor(m / a) + (m % a == 0 ? 0 : 1);
  print(Math.floor(x) * Math.floor(y));

  return 0;
}
