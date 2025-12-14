import sqlite3
import pandas as pd

conn = sqlite3.connect('kids.db')


query_regions = """
SELECT 
    ci.name as city_name,
    co.name as country_name,
    AVG(b.nice_score) as average_score,
    COUNT(c.id) as child_count,
    ci.lat,
    ci.lon
FROM children c
JOIN behavior b ON c.id = b.child_id
JOIN households h ON c.household_id = h.id
JOIN cities ci ON h.city_id = ci.id
JOIN countries co ON ci.country_code = co.code
WHERE b.year = 2025
GROUP BY ci.id     
ORDER BY average_score DESC
LIMIT 5
"""

df_regions = pd.read_sql_query(query_regions, conn)

print("🏆 Top 3 des villes les plus sages :")
print(df_regions.to_string())


import folium


m_regions = folium.Map(location=[20, 0], zoom_start=2)

for index, row in df_regions.iterrows():
   
    score_arrondi = round(row['average_score'], 2)
    
    popup_text = f"""
    <b>{row['city_name']} ({row['country_name']})</b><br>
    Score Moyen : {score_arrondi} / 10<br>
    Nombre d'enfants : {row['child_count']}
    """
    
    folium.Marker(
        location=[row['lat'], row['lon']],
        popup=folium.Popup(popup_text, max_width=300),
        
        icon=folium.Icon(color="green", icon="info-sign")
    ).add_to(m_regions)


m_regions.save("carte_top_regions.html")
import webbrowser, os
webbrowser.open("file://" + os.path.abspath("carte_top_regions.html"))