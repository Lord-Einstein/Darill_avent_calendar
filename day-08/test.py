import sqlite3
import pandas as pd

conn = sqlite3.connect('./kids.db')


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

import geopandas as gpd
import plotext as plt


url = "https://naturalearth.s3.amazonaws.com/110m_cultural/ne_110m_admin_0_countries.zip"
world = gpd.read_file(url)


plt.clear_data()
plt.theme('dark')
plt.title("SYSTEME DE TRAQUAGE...")


for geometry in world.geometry:
    
    if geometry.geom_type == 'Polygon':
        x, y = geometry.exterior.xy
        plt.plot(x, y, color="blue", marker="dot")
    
    elif geometry.geom_type == 'MultiPolygon':
        for part in geometry.geoms:
            x, y = part.exterior.xy
            plt.plot(x, y, color="blue", marker="dot")


lats = df_regions['lat'].tolist()
lons = df_regions['lon'].tolist()
cities = df_regions['city_name'].tolist()

plt.scatter(lons, lats, marker="fhd", color="red", label="CIBLES")


for i in range(len(cities)):
    
    plt.text(cities[i], lons[i] + 3, lats[i], color="white")


plt.xlim(-180, 180)
plt.ylim(-90, 90)
plt.plotsize(200, 200)

plt.show()