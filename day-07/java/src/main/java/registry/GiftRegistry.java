package registry;

import java.util.*;
import java.util.logging.Logger;
import java.util.logging.Level;

public class GiftRegistry { //HAHA fallait renommer le fichier aussi

    static final Logger logger = Logger.getLogger(GiftRegistry.class.getName());
    
    private List<Gift> gifts = new ArrayList<>();
    private Date lastUpdated = new Date();
    private boolean debug = true;

    
    private static final int SCORE_PACKED = 7;
    private static final int SCORE_UNPACKED = 3;
    private static final int SCORE_NOTE = 1;
    private static final int SCORE_BASE = 42;

    public GiftRegistry(List<Gift> initial) {

        if (initial != null) {
            this.gifts = new ArrayList<>(initial);
        }
    }

    public void addGift(String child, String giftName, Boolean packed) {

        if (child == null || child.isEmpty()) {
            logger.warning("Child name is missing. Cannot add gift.");
            return;
        }

        boolean exists = false;
        for (Gift g : gifts) {
            if (g.getChildName().equals(child) && g.getGiftName().equals(giftName)) {
                exists = true;
                break;
            }
        }

        if (!exists) {
            boolean isPacked = (packed != null) && packed;
            gifts.add(new Gift(child, giftName, isPacked, "ok"));
            this.lastUpdated = new Date();
        }
    }

    public Date getLastUpdated() {
        return lastUpdated;
    }

    public boolean markPacked(String child) {
        for (Gift g : gifts) {
            if (g.getChildName().equals(child)) {
                g.setPacked(true);
                this.lastUpdated = new Date();
                return true;
            }
        }
        return false;
    }

    public Gift findGiftFor(String child) {
        
        for (Gift g : gifts) {
            if (g.getChildName().equals(child)) {
                return g;
            }
        }
        return null;
    }

    public int computeElfScore() {
        int score = 0;
        for (Gift g : gifts) {
            
            score += (g.isPacked() ? SCORE_PACKED : SCORE_UNPACKED) 
                   + (g.getNotes() != null ? SCORE_NOTE : 0) 
                   + SCORE_BASE;
        }

        if (debug && logger.isLoggable(Level.INFO)) {
            logger.info("Computed score: " + score);
        }
        return score;
    }

    public static class Gift {
        private String childName;
        private String giftName;
        private boolean isPacked;
        private String notes;

        public Gift(String c, String g, boolean p, String n) {
            this.childName = c;
            this.giftName = g;
            this.isPacked = p;
            this.notes = n;
        }

        public String getChildName() { return childName; }
        public String getGiftName() { return giftName; }
        public boolean isPacked() { return isPacked; }
        public void setPacked(boolean p) { isPacked = p; }
        public String getNotes() { return notes; }
    }
}