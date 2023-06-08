use std::io::{self, Read};
use std::collections::BTreeSet;

fn main() {
    let mut buf = String::with_capacity(1005);
    io::stdin().read_to_string(&mut buf).unwrap();

    let mut substrs = BTreeSet::new();

    let len = buf.len();
    for i in 0..len {
        for j in i+1..len {
            substrs.insert(&buf[i..j]);
        }
    }

    println!("{}", substrs.len());
}
