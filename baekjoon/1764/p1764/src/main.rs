use std::io::{self, Read};
use std::fmt::Write;
use std::collections::{HashSet, BTreeSet};

fn main() {
    let mut buf = String::with_capacity(21000000);
    io::stdin().read_to_string(&mut buf).unwrap();
    let mut input = buf.split_ascii_whitespace();

    let n: usize = input.next().unwrap().parse().unwrap();
    let m: usize = input.next().unwrap().parse().unwrap();

    let mut names = HashSet::with_capacity(500000);
    for _i in 0..n {
        names.insert(input.next().unwrap());
    }

    let mut num = 0;
    let mut dup = BTreeSet::new();
    for _i in 0..m {
        let name = input.next().unwrap();
        if names.contains(name) {
            num += 1;
            dup.insert(name);
        }
    }

    let mut out = String::with_capacity(1050000);
    for name in dup {
        writeln!(out, "{}", name).unwrap();
    }

    print!("{}\n{}", num, out);
}
