use std::io;
use std::collections::HashSet;

fn main() {
    let mut buf = String::new();
    io::stdin().read_line(&mut buf).expect("read_line");

    let mut iter = buf.split_whitespace();
    let n: u32 = iter.next().expect("iter next").parse().expect("parse");
    let m: u32 = iter.next().expect("iter next").parse().expect("parse");

    let mut set = HashSet::new();
    for _i in 0..n {
        let mut buf = String::new();
        io::stdin().read_line(&mut buf).expect("read_line");
        set.insert(buf);
    }

    let mut sum = 0;
    for _i in 0..m {
        let mut buf = String::new();
        io::stdin().read_line(&mut buf).expect("read_line");

        if set.contains(&buf) {
            sum += 1;
        }
    }

    println!("{}", sum);

}
