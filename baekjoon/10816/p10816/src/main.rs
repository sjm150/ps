use std::io::{self, Read};
use std::collections::HashMap;
use std::fmt::Write;

fn main() {
    let mut buf = String::new();
    io::stdin().read_to_string(&mut buf).expect("read_to_string");
    let mut input = buf.split_ascii_whitespace();

    let n: usize = input.next().unwrap().parse().unwrap();

    let mut num_cards = HashMap::with_capacity(n);
    for _i in 0..n {
        let card = input.next().unwrap();
        let num = num_cards.entry(card).or_insert(0);
        *num += 1;
    }

    let m: usize = input.next().unwrap().parse().unwrap();

    let mut out = String::with_capacity(m * 2);
    for _i in 0..m {
        if let Some(num) = num_cards.get(input.next().unwrap()) {
            write!(out, "{} ", num).unwrap();
        } else {
            write!(out, "0 ").unwrap();
        }
    }

    println!("{}", out);
}
