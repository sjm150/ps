use std::io;
use std::collections::HashMap;
use std::fmt::Write;

fn main() {
    let mut buf = String::new();
    io::stdin().read_line(&mut buf).expect("read_line");
    let mut iter = buf.split_whitespace();
    let n: usize = iter.next().expect("iter next").parse().expect("parse");
    let m: usize = iter.next().expect("iter next").parse().expect("parse");

    let mut str_to_idx = HashMap::with_capacity(n);
    let mut idx_to_str = Vec::with_capacity(n);
    for i in 1..(n+1) {
        let mut buf = String::new();
        io::stdin().read_line(&mut buf).expect("read_line");

        str_to_idx.insert(buf.clone(), i);
        idx_to_str.push(buf);
    }

    let mut out = String::new();
    for _i in 0..m {
        let mut buf = String::new();
        io::stdin().read_line(&mut buf).expect("read_line");

        if let Ok(idx) = buf.trim().parse::<usize>() {
            writeln!(out, "{}", idx_to_str.get(idx-1).expect("does not exist").trim()).expect("write");
        } else {
            writeln!(out, "{}", str_to_idx.get(&buf).expect("does not exist")).expect("write");
        }
    }

    print!("{}", out);
}
