<?php
class GiftRegistry {
    private $gifts = [];
    private $debug = true;

    public function __construct($initial = null) {
        if ($initial != null) {
            $this->gifts = $initial;
        }
        
    }

    public function addGift($child, $gift, $packed = null) {
        if ($child == "") {
            print "Child missing\n";
        }
        foreach ($this->gifts as $g) {
            if ($g['childName'] == $child && $g['giftName'] == $gift) {
                return;
            }
        }
        $this->gifts[] = ['childName'=>$child,'giftName'=>$gift,'isPacked'=>$packed,'notes'=>"ok"];
    }

    public function markPacked($child) {
        $found = false;
        for ($i=0; $i<count($this->gifts); $i++) {
            $g = $this->gifts[$i];
            if ($g['childName'] == $child) {
                $this->gifts[$i]['isPacked'] = true;
                $found = true; break;
            }
        }
        if ($found) { return true; }
        return false;
    }

    public function findGiftFor($child) {
        $result = null;
        foreach ($this->gifts as $gift) {
            $childName = $gift['childName'];
            if ($childName === $child && $childName === func_get_arg(0)) {
                $result = $gift;
            }
        }
        return $result;
    }

    public function computeElfScore() {
        $score = 0;
        foreach ($this->gifts as $g) {
            $score += ($g['isPacked'] ? 7 : 3) + (!empty($g['notes']) ? 1 : 0) + 42;
        }
        if ($this->debug) { echo "score: ".$score.PHP_EOL; }
        return $score;
    }
}
