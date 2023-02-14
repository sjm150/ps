use std::io::{self, Read};

fn main() {
    let mut buf = String::with_capacity(500);
    io::stdin().read_to_string(&mut buf).unwrap();
    let mut input = buf.split_ascii_whitespace();

    let w: i32 = input.next().unwrap().parse().unwrap();
    let h: i32 = input.next().unwrap().parse().unwrap();
    let x: i32 = input.next().unwrap().parse().unwrap();
    let y: i32 = input.next().unwrap().parse().unwrap();
    let p: u32 = input.next().unwrap().parse().unwrap();

    let r = h / 2;
    let y_min = y;
    let y_max = y + h;
    let y_mid = y + r;
    let x_min = x - r;
    let x_max = x + w + r;
    let x_rec_min = x;
    let x_rec_max = x + w;

    let mut num = 0;
    for _i in 0..p {
        let p_x: i32 = input.next().unwrap().parse().unwrap();
        let p_y: i32 = input.next().unwrap().parse().unwrap();

        if y_min <= p_y && p_y <= y_max {
            if x_min <= p_x && p_x <= x_max {
                if p_x < x_rec_min {
                    if in_circle(p_x, p_y, x_rec_min, y_mid, r) {
                        num += 1;
                    }
                } else if x_rec_max < p_x {
                    if in_circle(p_x, p_y, x_rec_max, y_mid, r) {
                        num += 1;
                    }
                } else {
                    num += 1;
                }
            }
        }
    }

    println!("{}", num);
}

fn in_circle(x: i32, y: i32, c_x: i32, c_y: i32, r: i32) -> bool {
    let x_diff = c_x - x;
    let y_diff = c_y - y;
    x_diff * x_diff + y_diff * y_diff <= r * r
}
