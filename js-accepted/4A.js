// Problem #    : 4A
// Created on   : 2019-01-15 00:36:24
process.stdin.resume();
process.stdin.setEncoding("utf8");

var input = "",
  readline,
  print;

process.stdin.on("data", function(chunk) {
  input += chunk;
});

process.stdin.on("end", function() {
  input = input.split("\n");
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
  let l = readline();
  let n = Number(l);
  if (n > 2 && n % 2 == 0) {
    print("YES");
  } else {
    print("NO");
  }

  return 0;
}
