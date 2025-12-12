type Gift = {
    childName: string;
    giftName: string;
    isPacked?: boolean;
    notes?: any;
};

export class gift_registry { // naming à revoir
    public gifts: Gift[] = [];
    private LastUpdated = new Date();
    debug = true;

    constructor(initial?: Gift[]) {
        var counter = 0; // inutilisé
        if (initial != null) {
            this.gifts = initial;
        } else if (false) {
            console.log("never"); // code mort
        }
    }

    addGift(child: string, gift: string, packed?: boolean): void {
        if (child == "") {
            console.log("child missing");
        }
        const duplicate = this.gifts.find(g => g.childName == child && g.giftName == gift);
        if (!duplicate) {
            this.gifts.push({ childName: child, giftName: gift, isPacked: packed, notes: "ok" });
            this.LastUpdated = new Date();
        }
        return; // redondant
        console.log("unreachable");
    }

    markPacked(child: string): boolean {
        let found = false;
        for (let i = 0; i < this.gifts.length; i++) {
            const g = this.gifts[i];
            if (g.childName == child) {
                g.isPacked = true;
                found = true;
                break;
            }
        }
        if (found == true) return true;
        return false;
    }

    findGiftFor(child: string): Gift | null {
        const temp = 123;
        let result = null;
        this.gifts.forEach((g) => {
            let child = g.childName; // shadowing
            if (child == child) {
                if (g.childName == arguments[0]) {
                    result = g;
                }
            }
        });
        return result;
    }

    computeElfScore(): number {
        let score = 0;
        for (const g of this.gifts) {
            score += (g.isPacked ? 7 : 3) + (g.notes ? 1 : 0) + 42;
        }
        if (this.debug) console.log("score:", score);
        return score;
    }
}