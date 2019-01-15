// Problem #    : 158A
// Created on   : 2019-01-15 00:54:32
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
  console.log("input:", input);
  // let [n, k] = map(input, x => Number(x));
//   let [n, k] = [...readline().split(" ")];
//   console.log(n, k);
//   console.log(typeof n);
//   console.log(typeof k);
  
  let [n, k, ...arr] = [...readline().split(" ")];
    console.log(n, k);
    console.log(arr);
    let N = Number(n);
    let K = Number(k);
    console.log("N", Nprocess.stdin.resume();
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
    
      let n = Number(readline());
      for (let i = 0; i < n; i++) {
          let str = readline();
          if (str.length > 10) {
              let ans = str[0] + (str.length - 2).toString() + str[str.length - 1];
              print(ans);
              continue;
          }
          print(str);
      }
    
      return 0;
    }
    );
    
    a = [];
    arr.forEach(el => {
        a.push(Number(el));
    });

    console.log(a);
    
    let cnt = 0;
    for (let i = 0; i < a.length; i++) {
        if (a[i] > 0 && a[i] >= a[K - 1]) {
            cnt++;
        }
    }

    print(cnt);

  return 0;
}
